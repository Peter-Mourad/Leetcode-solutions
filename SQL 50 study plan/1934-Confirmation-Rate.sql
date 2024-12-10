select SU.user_id , round(COALESCE(count(CASE WHEN C.action = 'confirmed' THEN 1 ELSE Null END) * 1.0 / count(C.user_id), 0), 2) confirmation_rate
from Signups SU 
left join Confirmations C 
ON SU.user_id = C.user_id
group by SU.user_id;