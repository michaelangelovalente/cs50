SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN(
    SELECT id
    FROM movies
    JOIN stars ON movies.id = stars.movie_id
    WHERE stars.person_id  = (
        SELECT id
        FROM people
        WHERE UPPER(name) = "KEVIN BACON"
    )
) AND UPPER(people.name) <> "KEVIN BACON";