-- list number of movies with rating of 10.0

SELECT COUNT(movies.title) FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE ratings.rating = 10;
