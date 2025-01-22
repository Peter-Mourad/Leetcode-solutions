select id, 
        case 
            when mod(S.id, 2) = 1 and 
                S.id + 1 <= (select id from Seat order by id desc limit 1)
                then (select student from Seat where id = S.id + 1)
            when mod(S.id, 2) = 1 then S.student
            Else (select student from Seat where id = S.id - 1)
        End as student
From Seat S
order by id;