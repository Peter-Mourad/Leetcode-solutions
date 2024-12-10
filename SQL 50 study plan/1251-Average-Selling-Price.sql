select P.product_id, COALESCE(round(sum(U.units * P.price) / sum(U.units), 2), 0) average_price 
from Prices P
left join UnitsSold U 
on P.product_id = U.product_id 
and U.purchase_date between P.start_date and P.end_date
group by product_id;