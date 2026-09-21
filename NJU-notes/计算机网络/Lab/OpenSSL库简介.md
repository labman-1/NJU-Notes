## 1. `SSL_library_init()`
初始化 OpenSSL 库，加载必要的加密算法。

**函数原型：**
```c
void SSL_library_init(void);
```

**参数：**
- 无参数。

**返回值：**
- 无返回值。

**说明：**
- 必须在使用任何 OpenSSL 功能之前调用该函数。
- 加载加密算法（如 RSA、AES 等）和随机数生成器（RNG）。

## 2. `OpenSSL_add_all_algorithms()`
加载所有支持的加密算法。

**函数原型：**
```c
void OpenSSL_add_all_algorithms(void);
```

**参数：**
- 无参数。

**返回值：**
- 无返回值。

**说明：**
- 加载所有支持的加密算法（如 RSA、AES、SHA 等）。
- 通常与 `SSL_library_init()` 一起调用。

## 3. `SSL_load_error_strings()`
加载错误信息字符串，用于调试和错误处理。

**函数原型：**
```c
void SSL_load_error_strings(void);
```

**参数：**
- 无参数。

**返回值：**
- 无返回值。

**说明：**
- 加载错误信息字符串，方便在调试时打印详细的错误信息。
- 可以通过 `ERR_print_errors_fp()` 打印错误信息。

## 4. `ERR_print_errors_fp()`
打印 OpenSSL 错误信息。

**函数原型：**
```c
void ERR_print_errors_fp(FILE* fp);
```

**参数：**
- `fp`：指向 `FILE` 的指针，输出文件流（如 `stderr`）。

**返回值：**
- 无返回值。

**说明：**
- 打印 OpenSSL 的错误信息到指定的文件流。
- 用于调试和错误处理。

## 5. `TLS_server_method()`
获取 TLS 服务器方法，用于创建 SSL 上下文。

**函数原型：**
```c
const SSL_METHOD* TLS_server_method(void);
```

**参数：**
- 无参数。

**返回值：**
- 返回一个指向 `SSL_METHOD` 的指针，表示 TLS 服务器方法。

**说明：**
- 用于创建 TLS 服务器上下文。
- 适用于 HTTPS 服务器。

## 6. `SSL_CTX_new()`
创建一个新的 SSL 上下文。

**函数原型：**
```c
SSL_CTX* SSL_CTX_new(const SSL_METHOD* method);
```

**参数：**
- `method`：指向 `SSL_METHOD` 的指针，指定使用的 SSL/TLS 方法。

**返回值：**
- 成功时返回一个指向 `SSL_CTX` 的指针。
- 失败时返回 `NULL`。

**说明：**
- 根据指定的方法创建一个新的 SSL 上下文。
- 用于配置 SSL/TLS 的全局参数（如证书、私钥等）。

## 7. `SSL_CTX_use_certificate_file()`
加载 SSL 证书文件。

**函数原型：**
```c
int SSL_CTX_use_certificate_file(SSL_CTX* ctx, const char* file, int type);
```

**参数：**
- `ctx`：指向 `SSL_CTX` 的指针，SSL 上下文。
- `file`：证书文件路径。
- `type`：证书文件类型（如 `SSL_FILETYPE_PEM`）。

**返回值：**
- 成功时返回 1。
- 失败时返回 0 或负值。

**说明：**
- 从文件中加载 SSL 证书。
- 证书用于客户端验证服务器的身份。

## 8. `SSL_CTX_use_PrivateKey_file()`
加载 SSL 私钥文件。

**函数原型：**
```c
int SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type);
```

**参数：**
- `ctx`：指向 `SSL_CTX`（SSL 上下文）的指针。
- `file`：私钥文件路径。
- `type`：私钥文件类型（如 `SSL_FILETYPE_PEM`）。

**返回值：**
- 成功时返回 1。
- 失败时返回 0 或负值。

**说明：**
- 从文件中加载 SSL 私钥。
- 私钥用于解密客户端发送的加密数据。

## 9. `SSL_new()`
创建一个新的 SSL 对象。

**函数原型：**
```c
SSL* SSL_new(SSL_CTX* ctx);
```

**参数：**
- `ctx`：指向 `SSL_CTX`（SSL 上下文）的指针。

**返回值：**
- 成功时返回一个指向 `SSL` 的指针。
- 失败时返回 `NULL`。

**说明：**
- 根据指定的 SSL 上下文创建一个新的 SSL 对象。
- 用于处理单个 SSL/TLS 连接。

## 10. `SSL_set_fd()`
将 SSL 对象与套接字关联。

**函数原型：**
```c
int SSL_set_fd(SSL* ssl, int fd);
```

**参数：**
- `ssl`：指向 `SSL` 的指针，SSL 对象。
- `fd`：套接字（socket）描述符。

**返回值：**
- 成功时返回 1。
- 失败时返回 0。

**说明：**
- 将 SSL 对象与指定的套接字（Socket）关联，用于加密通信。

## 11. `SSL_accept()`
执行 SSL/TLS 握手过程。（一个函数，完成整个握手过程）

**函数原型：**
```c
int SSL_accept(SSL* ssl);
```

**参数：**
- `ssl`：指向 `SSL` 的指针，SSL 对象。

**返回值：**
- 成功时返回 1。
- 失败时返回 -1。

**说明：**
- 执行 SSL/TLS 握手过程，与客户端建立加密连接。

## 12. `SSL_read()`
从 SSL 连接中读取数据。

**函数原型：**
```c
int SSL_read(SSL* ssl, void* buf, int num);
```

**参数：**
- `ssl`：指向 `SSL` 的指针，SSL 对象。
- `buf`：指向缓冲区的指针，用于存储读取的数据。
- `num`：要读取的最大字节数。

**返回值：**
- 成功时返回读取的字节数。
- 失败时返回 -1。

**说明：**
- 从 SSL 连接中读取加密数据并解密后存储到缓冲区。

## 13. `SSL_write()`
向 SSL 连接中写入数据。

**函数原型：**
```c
int SSL_write(SSL* ssl, const void* buf, int num);
```

**参数：**
- `ssl`：指向 `SSL` 的指针，SSL 对象。
- `buf`：指向要写入的数据缓冲区的指针。
- `num`：要写入的字节数。

**返回值：**
- 成功时返回写入的字节数。
- 失败时返回 -1。

**说明：**
- 将数据加密后写入 SSL 连接。

## 14. `SSL_free()`
释放 SSL 对象。

**函数原型：**
```c
void SSL_free(SSL* ssl);
```

**参数：**
- `ssl`：指向 `SSL` 的指针，SSL 对象。

**返回值：**
- 无返回值。

**说明：**
- 释放 SSL 对象占用的资源。

## 15. `SSL_CTX_free()`
释放 SSL 上下文。

**函数原型：**
```c
void SSL_CTX_free(SSL_CTX* ctx);
```

**参数：**
- `ctx`：指向 `SSL_CTX` 的指针，SSL 上下文。

**返回值：**
- 无返回值。

**说明：**
- 释放 SSL 上下文占用的资源。

## 16. `SSL_get_fd()`
获取与 SSL 对象关联的套接字。

**函数原型：**
```c
int SSL_get_fd(SSL* ssl);
```

**参数：**
- `ssl`：指向 `SSL` 的指针，SSL 对象。

**返回值：**
- 返回与 SSL 对象关联的套接字文件描述符。

**说明：**
- 用于获取与 SSL 对象关联的套接字，以便后续操作。