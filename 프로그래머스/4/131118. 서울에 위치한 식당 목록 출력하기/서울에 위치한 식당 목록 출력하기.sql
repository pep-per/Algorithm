SELECT REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, ROUND(AVG(REVIEW_SCORE), 2) SCORE
FROM REST_INFO
LEFT JOIN REST_REVIEW
USING (REST_ID)
GROUP BY REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS
HAVING SCORE IS NOT NULL AND ADDRESS LIKE '서울%'
ORDER BY SCORE DESC, FAVORITES DESC