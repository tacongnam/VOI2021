
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

# Cash machine

Ta thấy công thức quy hoạch động như sau:

•Gọi $m[b]$ là số tiền nhỏ nhất mà phải trả nhiều tờ tiền nhất•Gọidp[b]là số lượng tờ tiền dùng để trảm[b]•Gọic(b)là mệnh giá tiền lớn nhất mà không vượt quáb•Dễ dàng thấy được công thức quy hoạch động như sau:dp[b] = max(dp[b−1], dp[b−c(b)] + 1)•Nếub−c(v)−c(v)≥c(v)thìdp[b] = max(dp[b−1−c(v)], dp[b−2×c(b)] + 2)•Gọitlà số lớn nhất màb−t×c(b)≥c(b)thì ta có công thức sau:dp[b] = max(dp[b−1−(t−1)×c(v)], dp[b−t×c(b)] +t)•Vớib−c(b)< c(b)ta có thể viết lại công thức thành:dp[b] = max(bmaxj=c(b)(dp[j−c(b)] + 1), dp[c(b)−1])•Vìdp[i]≥d[j]vớii > jdo đó:bmaxj=c(b)(dp[j−c(b)] + 1) =dp[b−c(b)]•Từ các công thức trên ta có thể viết lại công thức như sau:dp[b] = max(dp[b−t×c(b)] +t, dp[c(b)−1] + (t−1))Vìb−t×c(b)<b2, do đó số lượng mệnh giá tiền sử dụng để trảbsẽ không vượt quálogb. Do đó ta cóthể tính đượcdp[b]trong O(logb) khi đã chuẩn bị trước đượcdp[ai−1]
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTk3NjAzNjU4NywtNTMwNDM4OTUxLDE0NT
MzMDU5MTAsMjk4MzYwNTk3LC0zOTM5NTgxMjgsLTk2NDgwMjEz
NSw5MzU0Njc5OTksMTI2MjE2ODA4NiwtNTkxNzQ1ODA4LDEwOD
UyNDkzNjYsLTk0NTk3NTExOSwxNTk2ODc2OTQ3LDkwOTI5MTQx
NywyOTY2OTg5MjVdfQ==
-->