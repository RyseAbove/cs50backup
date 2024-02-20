-- list the names of people who starred in movies in 2004, ordered by birth year

SELECT people.name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth ASC;


-- list the titles of movies with the word kindness in the title that also stars anyone named Tim or Daniel, ranked in order or rating (high to low)

-- SELECT movies.title FROM movies
-- JOIN ratings ON movies.id = ratings.movie_id
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON stars.person_id = people.id
-- WHERE movies.title LIKE '%kindness%' AND (people.name LIKE '%Tim%' OR people.name LIKE '%Daniel%')
-- ORDER BY ratings.rating DESC;
