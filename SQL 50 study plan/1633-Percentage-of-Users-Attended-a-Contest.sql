select contest_id, Round(count(user_id) / (select count(user_id) from Users) * 100.0, 2) percentage
From Register
Group by contest_id
Order by percentage DESC, contest_id ASC;