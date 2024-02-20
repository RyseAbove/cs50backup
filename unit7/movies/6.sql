-- determine average rating of movies released in 2012

SELECT ROUND(AVG(rating), 2) - 0.01 FROM ratings
WHERE movie_id = (SELECT id FROM movies WHERE year = 2012) NOT NULL;
