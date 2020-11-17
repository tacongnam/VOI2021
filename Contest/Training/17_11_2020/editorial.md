
# A. Evacuation (J - ACM ICPC miền Bắc 20)
Chặt nhị phân thời gian. Với mỗi thời gian t sử dụng luồng để kiểm tra có tồn tại cách để chia mọi người vào các hầm trú hay không.

# B. Planes
Chỉ là xếp thí sinh trước mà thôi

+) Nếu tạo đường được -> tạo luôn

+) Nếu tạo đường mà cần phải dùng cung ngược -> chắc chắn những đỉnh đã tạo trước nó phải tìm được một đường khác để tạo đường (giống giống cặp ghép)

-> Tạo trước mạng với những 
+) Chú ý: Sau khi kiểm tra xem có kết quả hay không, ta không reset lại flow mà add tiếp cạnh rồi chạy tiếp maxflow
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTI2MjE2ODA4NiwtNTkxNzQ1ODA4LDEwOD
UyNDkzNjYsLTk0NTk3NTExOSwxNTk2ODc2OTQ3LDkwOTI5MTQx
NywyOTY2OTg5MjVdfQ==
-->