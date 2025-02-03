SELECT ID, (CASE 
            WHEN COLONY_NAME <= 25 THEN 'CRITICAL'
            WHEN COLONY_NAME <= 50 THEN 'HIGH'
            WHEN COLONY_NAME <= 75 THEN 'MEDIUM'
            ELSE 'LOW'
            END) AS COLONY_NAME
FROM (SELECT ID, ranking/total*100 AS COLONY_NAME
    FROM (SELECT ID, 
         RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) 
         AS ranking,
         COUNT(*) OVER () AS total
         FROM ECOLI_DATA) AS sub) AS sub2
ORDER BY ID;