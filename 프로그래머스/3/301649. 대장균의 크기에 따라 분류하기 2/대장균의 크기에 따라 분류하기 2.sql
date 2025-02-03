SELECT ID, (CASE 
            WHEN ranking/total*100 <= 25 THEN 'CRITICAL'
            WHEN ranking/total*100 <= 50 THEN 'HIGH'
            WHEN ranking/total*100 <= 75 THEN 'MEDIUM'
            ELSE 'LOW'
            END) AS COLONY_NAME
FROM (SELECT ID, 
         RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) 
         AS ranking,
         COUNT(*) OVER () AS total
         FROM ECOLI_DATA)
     AS sub
ORDER BY ID;