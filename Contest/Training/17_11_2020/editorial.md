
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

•Gọi $m[b]$ là số tiền nhỏ nhất mà phải trả nhiều tờ tiền nhất

•Gọi $dp[b]$ là số lượng tờ tiền dùng để trả $m[b]$

•Gọi $c(b)$ là mệnh giá tiền lớn nhất mà không vượt quá $b$

•Dễ dàng thấy được công thức quy hoạch động như sau: $dp[b] = max(dp[b−1], dp[b−c(b)] + 1)$

•Nếu $b−c(v)−c(v) \geq c(v)$ thì $dp[b] = max(dp[b−1−c(v)], dp[b−2×c(b)] + 2)$

•Gọi $t$ là số lớn nhất mà $b−t×c(b) \geq c(b)$ thì ta có công thức sau: $dp[b] = max(dp[b−1−(t−1)×c(v)], dp[b−t×c(b)] +t)$

•Với $b−c(b) < c(b)$ ta có thể viết lại công thức thành: $dp[b] = max(bmaxj=c(b)(dp[j−c(b)] + 1), dp[c(b)−1])•Vìdp[i]≥d[j]vớii > jdo đó:bmaxj=c(b)(dp[j−c(b)] + 1) =dp[b−c(b)]•Từ các công thức trên ta có thể viết lại công thức như sau:dp[b] = max(dp[b−t×c(b)] +t, dp[c(b)−1] + (t−1))Vìb−t×c(b)<b2, do đó số lượng mệnh giá tiền sử dụng để trảbsẽ không vượt quálogb. Do đó ta cóthể tính đượcdp[b]trong O(logb) khi đã chuẩn bị trước đượcdp[ai−1]
<!--stackedit_data:
eyJoaXN0b3J5IjpbNzE2MDczNTY2LC01MzA0Mzg5NTEsMTQ1Mz
MwNTkxMCwyOTgzNjA1OTcsLTM5Mzk1ODEyOCwtOTY0ODAyMTM1
LDkzNTQ2Nzk5OSwxMjYyMTY4MDg2LC01OTE3NDU4MDgsMTA4NT
I0OTM2NiwtOTQ1OTc1MTE5LDE1OTY4NzY5NDcsOTA5MjkxNDE3
LDI5NjY5ODkyNV19
-->