-- list all names of movies and their ratings from 2010, descending by rating
-- if same rating, alphabetically by title

SELECT movies.title, ratings.rating FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating IS NOT NULL AND movies.year = 2010
ORDER BY ratings.rating DESC, movies.title;
