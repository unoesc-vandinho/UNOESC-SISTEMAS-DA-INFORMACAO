#!/usr/bin/env bash
# ==============================================================================
# Script para converter Markdown (.md) em PDF autêntico LaTeX (UNOESC)
# Uso: ./scripts/gerar-pdf.sh caminho/para/arquivo.md
# ==============================================================================

set -o pipefail

if [ -z "$1" ]; then
  echo "Uso: $0 <arquivo.md>"
  exit 1
fi

MD_FILE="$(realpath "$1")"
DIR="$(dirname "$MD_FILE")"
BASENAME="$(basename "$MD_FILE" .md)"
TEX_FILE="$DIR/$BASENAME.tex"
PDF_FILE="$DIR/$BASENAME.pdf"

SCRIPT_DIR="$(dirname "$(realpath "$0")")"
REPO_ROOT="$(dirname "$SCRIPT_DIR")"
TEMPLATE="$REPO_ROOT/_modelos-e-documentos/template-unoesc.tex"

if [ ! -f "$TEMPLATE" ]; then
  echo "❌ Erro: Template não encontrado em $TEMPLATE"
  exit 1
fi

echo "📄 1. Traduzindo Markdown para LaTeX com Pandoc..."
pandoc "$MD_FILE" \
  --template="$TEMPLATE" \
  --listings \
  -f markdown \
  -t latex \
  -o "$TEX_FILE"

echo "🐳 2. Compilando PDF com Docker (texlive/texlive)..."
# Executa a compilação duas vezes (para sumário e referências)
docker run --rm -v "$DIR:/work:Z" -w /work texlive/texlive:latest pdflatex -interaction=nonstopmode "$BASENAME.tex" > /dev/null 2>&1 || true
docker run --rm -v "$DIR:/work:Z" -w /work texlive/texlive:latest pdflatex -interaction=nonstopmode "$BASENAME.tex" > /dev/null 2>&1 || true

# Limpa arquivos temporários
rm -f "$DIR/$BASENAME.aux" "$DIR/$BASENAME.log" "$DIR/$BASENAME.out" "$DIR/$BASENAME.toc" "$DIR/$BASENAME.tex"

if [ -f "$PDF_FILE" ]; then
  echo "🎉 Sucesso! PDF gerado em: $PDF_FILE"
else
  echo "❌ Erro: O PDF não pôde ser gerado. Verifique a formatação do arquivo Markdown."
  exit 1
fi
