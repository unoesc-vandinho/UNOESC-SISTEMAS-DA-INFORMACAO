document.addEventListener('DOMContentLoaded', async () => {
    const movieContainer = document.getElementById('movie');
    const modalElement = document.getElementById('movieModal');
    const modalBody = document.getElementById('movieModalBody');
    const trailerLink = document.getElementById('trailerLink');

    if (!movieContainer || !modalElement || !modalBody || !trailerLink) return;

    const modal = new bootstrap.Modal(modalElement, {
        backdrop: true,
        keyboard: true,
        focus: true
    });

    function getYoutubeEmbedUrl(videoId) {
        if (!videoId) return '';
        return `https://www.youtube.com/embed/${videoId}?autoplay=1&rel=0`;
    }

    function renderMovieDetails(movie) {
        document.getElementById('movieModalLabel').textContent = movie.titulo;
        modalBody.innerHTML = `
            <div class="movie-modal-content">
                <div class="row g-3 align-items-center">
                    <div class="col-md-5">
                        <img src="${movie.img || 'source/img/placeholder.png'}" alt="${movie.titulo}" class="img-fluid rounded shadow-sm movie-modal-poster">
                    </div>
                    <div class="col-md-7">
                        <p class="mb-2"><strong>Título original:</strong> ${movie.titulo_original || '-'}</p>
                        <p class="mb-2"><strong>Ano:</strong> ${movie.ano || '-'}</p>
                        <p class="mb-2"><strong>Gênero:</strong> ${movie.genero || '-'}</p>
                        <p class="mb-2"><strong>Diretor:</strong> ${movie.diretor || '-'}</p>
                        <p class="mb-0"><strong>Sinopse:</strong> ${movie.sinopse || '-'}</p>
                    </div>
                </div>
            </div>
        `;

        trailerLink.disabled = !movie.trailer;
        trailerLink.textContent = movie.trailer ? 'Assistir trailer' : 'Trailer indisponível';
        trailerLink.classList.toggle('disabled', !movie.trailer);
    }

    function renderTrailer(movie) {
        const embedUrl = getYoutubeEmbedUrl(movie.trailer);
        if (!embedUrl) {
            renderMovieDetails(movie);
            return;
        }

        document.getElementById('movieModalLabel').textContent = `${movie.titulo} | Trailer`;
        modalBody.innerHTML = `
            <div class="trailer-wrapper">
                <div class="ratio ratio-16x9 trailer-frame">
                    <iframe
                        src="${embedUrl}"
                        title="Trailer de ${movie.titulo}"
                        frameborder="0"
                        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
                        referrerpolicy="strict-origin-when-cross-origin"
                        allowfullscreen>
                    </iframe>
                </div>
                <div class="mt-3 trailer-meta">
                    <h6 class="mb-2">${movie.titulo}</h6>
                    <p class="mb-0"><strong>Gênero:</strong> ${movie.genero || '-'} · <strong>Ano:</strong> ${movie.ano || '-'}</p>
                </div>
            </div>
        `;

        trailerLink.textContent = 'Voltar ao resumo';
        trailerLink.disabled = false;
        trailerLink.classList.remove('disabled');
    }

    try {
        const response = await fetch('source/movie-BD.json');
        if (!response.ok) throw new Error('Erro ao carregar o JSON dos filmes');

        const movies = await response.json();

        movieContainer.innerHTML = movies.map((movie) => `
            <div class="col-lg-3 col-md-6 mb-4">
                <div class="card movie h-100 shadow-sm open-modal" data-id="${movie.id}" role="button" tabindex="0" aria-label="Abrir detalhes de ${movie.titulo}">
                    <div class="img">
                        <img src="${movie.img || 'source/img/placeholder.png'}" alt="${movie.titulo}" class="card-img-top" style="height: 420px; object-fit: cover;">
                    </div>
                    <div class="card-body">
                        <div class="movie-title mb-2">
                            <h2 class="h5">${movie.titulo}</h2>
                        </div>
                    </div>
                </div>
            </div>
        `).join('');

        document.querySelectorAll('.open-modal').forEach((card) => {
            card.addEventListener('click', (event) => {
                const movieId = Number(event.currentTarget.dataset.id);
                const movie = movies.find((item) => item.id === movieId);

                if (!movie) return;

                renderMovieDetails(movie);
                modal.show();
            });

            card.addEventListener('keydown', (event) => {
                if (event.key === 'Enter' || event.key === ' ') {
                    event.preventDefault();
                    card.click();
                }
            });
        });

        trailerLink.addEventListener('click', () => {
            const activeMovieId = Number(document.querySelector('.open-modal.active')?.dataset.id);
            const currentMovie = movies.find((movie) => movie.id === activeMovieId);

            if (!currentMovie) return;

            if (trailerLink.textContent === 'Voltar ao resumo') {
                renderMovieDetails(currentMovie);
                return;
            }

            renderTrailer(currentMovie);
        });

        document.querySelectorAll('.open-modal').forEach((card) => {
            card.addEventListener('click', () => {
                document.querySelectorAll('.open-modal').forEach((item) => item.classList.remove('active'));
                card.classList.add('active');
            });
        });

    } catch (error) {
        movieContainer.innerHTML = `
            <div class="col-12">
                <div class="alert alert-danger" role="alert">
                    ${error.message}
                </div>
            </div>
        `;
    }

    modalElement.addEventListener('hidden.bs.modal', () => {
        document.body.classList.remove('modal-open');
    });
});


