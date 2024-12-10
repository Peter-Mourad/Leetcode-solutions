select ST.student_id, ST.student_name, SU.subject_name, (count(E.student_id)) as attended_exams 
from Students as ST
cross join Subjects as SU
left join Examinations as E
ON E.student_id = ST.student_id and E.subject_name = SU.subject_name
group by subject_name, student_id
order by student_id, subject_name;