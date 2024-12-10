select E.name, B.bonus from Employee as E
left join Bonus as B
on B.empId = E.empId
where B.bonus < 1000 or B.bonus is null;