SELECT requester_id AS id, COUNT(distinct friend_id) AS num
FROM (
    SELECT requester_id, accepter_id AS friend_id FROM RequestAccepted
    UNION
    SELECT accepter_id, requester_id AS friend_id FROM RequestAccepted
) AS friends
GROUP BY id
ORDER BY num DESC
LIMIT 1;
