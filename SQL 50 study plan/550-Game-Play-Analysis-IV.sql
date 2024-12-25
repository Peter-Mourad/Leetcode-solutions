SELECT 
    ROUND(COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM
    Activity a
JOIN
    (SELECT player_id, MIN(event_date) AS first_login
     FROM Activity
     GROUP BY player_id) first_logins
    ON a.player_id = first_logins.player_id
JOIN
    Activity a2
    ON a.player_id = a2.player_id
    AND DATEDIFF(a2.event_date, a.event_date) = 1
WHERE
    a.event_date = first_logins.first_login;