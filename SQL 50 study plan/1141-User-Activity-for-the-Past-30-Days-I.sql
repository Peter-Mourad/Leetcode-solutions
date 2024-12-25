SELECT activity_date day, COUNT(DISTINCT user_id) active_users
FROM Activity
WHERE DATEDIFF("2019-07-27", activity_date) BETWEEN 0 AND 29
GROUP BY activity_date;