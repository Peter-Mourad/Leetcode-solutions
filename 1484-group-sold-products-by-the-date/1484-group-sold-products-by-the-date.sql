# Write your MySQL query statement below
select sell_date, 
count(distinct product) as num_sold, 
GROUP_CONCAT(DISTINCT product ORDER BY product ASC separator ',') AS products 
from Activities
group by sell_date
order by sell_date;