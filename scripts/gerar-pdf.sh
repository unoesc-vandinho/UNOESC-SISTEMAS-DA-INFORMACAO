#!/usr/bin/env bash
# ==============================================================================
# Script para converter Markdown (.md) em PDF autêntico LaTeX (UNOESC)
# Uso: ./scripts/gerar-pdf.sh caminho/para/arquivo.md
# ==============================================================================

set -e

if [ -z "$1" ]; then
  echo "Uso: $0 <arquivo.md>"
  exit 1
fi

MD_FILE="$1"
DIR=$(dirname "$MD_FILE")
BASENAME=$(basename "$MD_FILE" .md)
TEX_FILE="$DIR/$BASENAME.tex"
PDF_FILE="$DIR/$BASENAME.pdf"
TEMPLATE="$(pwd)/_modelos-e-documentos/template-unoesc.tex"

echo "📄 1. Traduzindo Markdown para LaTeX com Pandoc..."
pandoc "$MD_FILE" \
  --template="$TEMPLATE" \
  --listings \
  -f markdown \
  -t latex \
  -o "$TEX_FILE"

echo "🐳 2. Compilando PDF com Docker (texlive/texlive)..."
docker run --rm \
  -v "$(pwd):/work" \
  -w "/work/$DIR" \
  texlive/texlive:latest \
  pdflatex -interaction=nonstopmode "$BASENAME.tex" > /dev/null

# Segunda passada para gerar sumário (TOC) perfeitamente
docker run --rm \
  -v "$(pwd):/work" \
  -w "/work/$DIR" \
  texlive/texlive:latest \
  pdflatex -interaction=nonstopmode "$BASENAME.tex" > /dev/null

echo "🧹 3. Limpando arquivos temporários..."
rm -f "$DIR/$BASENAME.aux" "$DIR/$BASENAME.log" "$DIR/$BASENAME.out" "$DIR/$BASENAME.toc" "$DIR/$BASENAME.tex"

echo "🎉 Sucesso! PDF gerado em: $PDF_FILE"
