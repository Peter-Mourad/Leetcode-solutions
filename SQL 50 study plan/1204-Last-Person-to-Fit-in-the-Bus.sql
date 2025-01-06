SELECT q1.person_name
FROM Queue q1
JOIN (
    SELECT person_id, person_name, weight,
           @cumulative_sum := @cumulative_sum + weight AS cumulative_sum
    FROM Queue, (SELECT @cumulative_sum := 0) AS init
    ORDER BY turn
) AS q2 ON q1.person_id = q2.person_id
WHERE q2.cumulative_sum <= 1000
ORDER BY q1.turn DESC
LIMIT 1;