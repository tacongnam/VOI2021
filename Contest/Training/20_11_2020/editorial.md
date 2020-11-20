# HAMMING DISTANCE 

Gọi dp[i][j][k] là số lượng số sao cho 8 bit đầu lập thành số i và khoảng cách hamming giữa 8 bit sau của số đó và j là k.

# XOR THE GRAPH

Sử dụng ý tưởng tô màu đồ thị. Chú ý verdict MLE on test 42.

# INVITED SPEAKERS

Duyệt hoán vị rồi nối hai điểm tương ứng bằng 1 đoạn thẳng.
Xét hai cặp điểm (a1, b1), (a2, b2) cắt nhau. Chúng ta có thể nối lại bằng cách (a1, b2), (a2, b1). Do (a1, b2) + (a2, b1) < (a1, b1) + (a2, b2).
Do đó, hoán vị có tổng khoảng cách giữa hai điểm xanh và đỏ là nhỏ nhất là đáp án.

# SEREJA AND LCM

dp[i][l]: tạo được i số, lcm của a1 -> ai = l
lcm = x chia hết cho D <=> gcd(x, D) = D.
gcd(D, lcm(x, l))

# SWAP AND FLIP


<!--stackedit_data:
eyJoaXN0b3J5IjpbMjIzMjYyMDM2LC0xMTE4NTY2Mzk4LDIzNj
EwNzM4NF19
-->