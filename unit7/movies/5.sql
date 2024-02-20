-- list the titles and release dates of every harry potter movie in chronological order

SELECT title, year FROM movies
WHERE title LIKE '%Harry Potter%'
ORDER BY year;
