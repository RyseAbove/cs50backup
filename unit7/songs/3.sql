-- list names of top 5 longest songs, decreasing

SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;
