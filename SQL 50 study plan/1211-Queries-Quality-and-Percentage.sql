select query_name, round(avg(rating / position), 2) quality, 
round(sum(case when rating < 3 then 1 else 0 end) * 100.0/ count(*), 2)  poor_query_percentage
From Queries Q
Group by query_name;