(
    SELECT name AS results FROM MovieRating 
    JOIN Users USING(user_id)
    GROUP BY user_id
    ORDER BY COUNT(user_id) DESC, name
    LIMIT 1
)

UNION ALL

(
    SELECT title AS results FROM Movies
    JOIN MovieRating USING(movie_id)
    WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
    GROUP BY movie_id
    ORDER BY AVG(rating) DESC, title
    LIMIT 1
);