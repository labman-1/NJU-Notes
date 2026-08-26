**两种分层方式**：
- OSI Reference model
	- Never lived up to early promises
	- 它由国际标准化组织（ISO）在1984年提出，是一个**理论参考模型**
- TCP/IP protocol suite
	- Most widely used
![[Lesson 1 introduction(2)_202608261039.jpg]]

# Delay
- Transmission delay
	- 把数据包推送到链路上所需的时间。
	- 决定因素：数据包大小和网卡的带宽
- Propagation delay(传播时延)
	- 一个比特在物理介质中以光速（或接近光速）传播到目的地所需的时间。
	- 决定因素：物理距离和介质材料
- Processing delay
	- 路由器或交换机收到一个数据包，检查它的头部信息（校验和错、查表决定转发到哪个端口）所花的时间。
	- 决定因素：路由器CPU算力
- Queuing delay
	- “多打一”的情况（多个入口一个出口，在同一时间撞一块了）
	- 决定因素：拥堵情况