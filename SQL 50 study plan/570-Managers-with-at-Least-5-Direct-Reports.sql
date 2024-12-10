select E2.name from Employee E1
inner join Employee E2 ON E1.managerId = E2.id
Group by E2.id
Having count(E1.managerId) >= 5;