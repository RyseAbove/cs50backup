-- list titles of movies starring Johnny Depp and Helena Bonham Carter together

SELECT sub.title
FROM
    (
    SELECT * FROM movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN people ON people.id = stars.person_id
    WHERE people.name = 'Johnny Depp'
    ) sub
JOIN movies ON movies.id = sub.id
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id  = stars.person_id
WHERE people.name = 'Helena Bonham Carter';
