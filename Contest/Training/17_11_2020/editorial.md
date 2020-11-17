
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

# C. LAMPS

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTM5Mzk1ODEyOCwtOTY0ODAyMTM1LDkzNT
Q2Nzk5OSwxMjYyMTY4MDg2LC01OTE3NDU4MDgsMTA4NTI0OTM2
NiwtOTQ1OTc1MTE5LDE1OTY4NzY5NDcsOTA5MjkxNDE3LDI5Nj
Y5ODkyNV19
-->