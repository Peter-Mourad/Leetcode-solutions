SELECT DISTINCT(l1.num) as ConsecutiveNums FROM Logs l1
LEFT JOIN Logs l2 ON l1.id + 1 = l2.id
LEFT JOIN Logs l3 ON l1.id + 2 = l3.id
WHERE l1.num = l2.num AND l2.num = l3.num;