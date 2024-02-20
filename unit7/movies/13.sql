-- list names of all people who starred in movies with Kevin Bacon

SELECT people.name
FROM
    (
    SELECT * FROM movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN people ON people.id = stars.person_id
    WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
    ) sub
JOIN movies ON movies.id = sub.id
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id  = stars.person_id
WHERE people.name != 'Kevin Bacon';
