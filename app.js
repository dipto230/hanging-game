document.addEventListener('DOMContentLoaded', () => {
    const productsContainer = document.querySelector('.products');
    fetch('/api/products')
        .then(response => response.json())
        .then(products => {
            products.forEach(product => {
                const productElement = document.createElement('div');
                productElement.classList.add('product');
                productElement.innerHTML = `
                    <h2>${product.name}</h2>
                    <p>${product.description}</p>
                    <p>$${product.price}</p>
                `;
                productsContainer.appendChild(productElement);
            });
        });
});
