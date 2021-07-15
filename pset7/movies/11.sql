SELECT title
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON movies.id = stars.movie_id
WHERE stars.person_id IN(
    SELECT id
    FROM people
    WHERE UPPER(name) = "CHADWICK BOSEMAN"
)
ORDER BY ratings.rating DESC LIMIT 5;