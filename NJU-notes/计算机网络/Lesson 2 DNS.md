DNS即从域名到ip的映射。可以理解为一个key-value的数据库。

Domains are subtrees.
Name is a root-to-leaf path.
RR format：（name, value,type,ttl）
DNS默认传输协议为UDP，默认端口为53.
DDOS攻击：使用大量边缘设备（肉机）向服务器发送大量报文，后来更常见的是向DNS发送大量域名解析请求。

# Electronic Mail
One of most heavily used apps on Internet.
SMTP(Simple Mail Transfer Protocol):
- Delivery of simple text message
MIME: Muti-purpose Internet Mail Extension

POP
IMAP