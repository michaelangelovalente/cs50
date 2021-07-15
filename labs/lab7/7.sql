SELECT ROUND(AVG(energy), 2) FROM songs WHERE artist_id IN(SELECT id FROM artists WHERE UPPER(name) = "Drake");
