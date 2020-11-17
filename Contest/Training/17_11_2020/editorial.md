
# A. Evacuation (J - ACM ICPC miền Bắc 2020)
Chặt nhị phân thời gian. Với mỗi thời gian t sử dụng luồng để kiểm tra có tồn tại cách để chia mọi người vào các hầm trú hay không.

# B. Planes
> Nhận xét
>
>+) Nếu tạo đường được -> tạo luôn
>
>+) Nếu tạo đường mà cần phải dùng cung ngược -> chắc chắn những đỉnh đã tạo trước nó phải tìm được một đường khác để tạo đường (giống giống cặp ghép)

-> Tạo trước mạng với những người tham gia cuộc thi

-> Kiểm tra xem có thể xếp hay không

-> Thêm vào mạng những người còn lại

-> Chạy thuật toán maxflow

+) Chú ý: Sau khi kiểm tra xem có kết quả hay không, ta không reset lại flow mà add tiếp cạnh rồi chạy tiếp maxflow

# C. Lamps

# D. Erase to max
Làm làm là ra

# Cash machine (Tag: Dễ dàng thấy)

Ta thấy công thức quy hoạch động như sau:

• Gọi $m[b]$ là số tiền nhỏ nhất mà phải trả nhiều tờ tiền nhất

• Gọi $dp[b]$ là số lượng tờ tiền dùng để trả $m[b]$

• Gọi $c(b)$ là mệnh giá tiền lớn nhất mà không vượt quá $b$

• Dễ dàng thấy được công thức quy hoạch động như sau: $dp[b] = max(dp[b−1], dp[b−c(b)] + 1)$

• Nếu $b−c(b)−c(b) \geq c(b)$ thì $dp[b] = max(dp[b−1−c(b)], dp[b−2×c(b)] + 2)$

• Gọi $t$ là số lớn nhất mà $b−t×c(b) \geq c(b)$ thì ta có công thức sau: $dp[b] = max(dp[b−1−(t−1)×c(b)], dp[b−t×c(b)] +t)$

• Với $b−c(b) < c(b)$ ta có thể viết lại công thức thành: $dp[b] = max(max_{j=c(b)}^{b}(dp[j−c(b)] + 1), dp[c(b)−1])$.

• Vì $dp[i]\geq d[j]$ với $i > j$ do đó: $max_{j=c(b)}^{b}(dp[j−c(b)] + 1) =dp[b−c(b)]$

• Từ các công thức trên ta có thể viết lại công thức như sau: $dp[b] = max(dp[b−t×c(b)] +t, dp[c(b)−1] + (t−1))$. Vì $b−t×c(b)<\frac{b}{2}$, do đó số lượng mệnh giá tiền sử dụng để trả $b$ sẽ không vượt quá $logb$. Do đó ta cóthể tính được $dp[b]$ trong $O(logb)$ khi đã chuẩn bị trước được $dp[a_i−1]$
<!--stackedit_data:
eyJoaXN0b3J5IjpbNzY4ODg0MjksMTE0MTUxMzM4MywtNTMwND
M4OTUxLDE0NTMzMDU5MTAsMjk4MzYwNTk3LC0zOTM5NTgxMjgs
LTk2NDgwMjEzNSw5MzU0Njc5OTksMTI2MjE2ODA4NiwtNTkxNz
Q1ODA4LDEwODUyNDkzNjYsLTk0NTk3NTExOSwxNTk2ODc2OTQ3
LDkwOTI5MTQxNywyOTY2OTg5MjVdfQ==
-->