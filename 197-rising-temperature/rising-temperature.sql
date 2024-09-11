SELECT a.id
FROM Weather as a,Weather as b
WHERE a.temperature>b.temperature
AND DATEDIFF(a.recordDate,b.recordDate)=1