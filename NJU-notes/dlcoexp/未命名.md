
### 一、 剖析：XDC 到底改了什么？为什么？

#### 1. 刚才改了什么？
以开关 `SW[0]` 为例，在原本的 `nexysa7.xdc` 模板中，它是这样的：
```text
#set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { sw[0] }]; 
```
改完之后，它变成了：
```text
set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { SW[0] }]
```

#### 2. 为什么这样改？（底层原理）
*   **去掉 `#` 号（激活）：** `#` 是约束文件里的注释符。去掉它，就等于告诉物理编译器：“**听着，我要启用板子上的 J15 针脚！**” 如果不去掉 `#`，Vivado 在布线时就会完全忽略这个物理针脚，你的开关就不会起任何作用。
*   **改写 `get_ports { ... }` 里的名字（桥接）：** 
    你的顶层代码 `top_lab01.v` 中声明的输入端口是大写的 **`SW`**。但原始模板里写的是小写的 `sw[0]`。
    *   **核心逻辑：** 约束文件就像是一个**“物理连线对应字典”**：
        `PACKAGE_PIN J15`（物理硬件上的 J15 开关脚） $\leftrightarrow$ `get_ports { SW[0] }`（代码里叫 `SW[0]` 的那根输入线）。
    *   这两边的名字必须 **100% 连字母大小写都一模一样**，物理编译器才能把它们成功“焊接”起来。

#### 3. 以后要自己写（或修改）约束文件，该如何思考？
你只需要遵循一个极简的**“引脚对齐三步法”**：
1.  **看我的顶层模块代码：** 我的 `module top` 声明了哪些引脚名？（比如我声明了 `LED[4]`、`AN[0]`）。
2.  **找板子的 XDC 模板：** 找到对应的外设区域（如 `## LEDs` 或 `## 7 segment display`）。
3.  **删 `#` 改名字：** 删掉对应引脚行开头的 `#`，然后把大括号 `{}` 里的名字，**改成你代码中定义的引脚名字**。

---

### 二、 扫盲：Vivado 左侧 Flow Navigator 都是干什么的？

左侧的导航栏，其实是**一块芯片从图纸（代码）到物理落地的“标准生产流水线”**。从上到下代表了五个紧密相扣的阶段：

```text
 1. PROJECT MANAGER (图纸管理)  <--- 你现在管理代码、约束文件的地方
        |
 2. SIMULATION (虚拟仿真)       <--- 用波形图软件测试逻辑（不涉及硬件）
        |
 3. RTL ANALYSIS (逻辑电路图)    <--- 把你的代码“画”成基本的门电路逻辑图，供你检查
        |
 4. SYNTHESIS (逻辑综合)        <--- 把代码翻译成 FPGA 专用的基本砖块（LUT/DFF）
        |
 5. IMPLEMENTATION (物理布局布线)<--- 决定这些砖块具体放在芯片内哪个位置，如何走线
        |
 6. PROGRAM AND DEBUG (烧录落盘)<--- 生成最终烧录文件（Bitstream），写进物理开发板
```

#### 逐项详解：
*   **PROJECT MANAGER（项目管理器）：** 
    *   *Settings / Add Sources:* 用于配置项目、添加或删除你的 `.v` 代码和 `.xdc` 文件。
*   **IP INTEGRATOR（IP 集成器）：**
    *   用于可视化画模块连线图（通常大三做 SoC 高级项目时用），当前数电实验可以直接忽略。
*   **SIMULATION（仿真）：**
    *   *Run Simulation:* 启动虚拟示波器。在不通电、不插板子的情况下，通过 Testbench 观察波形，验证逻辑是否正确。
*   **RTL ANALYSIS（RTL 逻辑分析）：**
    *   *Open Elaborated Design:* 极其强大的功能！它能把你的代码转成**“电路原理图（Schematic）”**。建议你平时写完代码点一下它，看看生成的原理图是不是和你脑海中想画的与门、或门、选择器一模一样。
*   **SYNTHESIS（综合）：**
    *   *Run Synthesis:* 逻辑翻译官。把你的 `assign`、`always` 等代码，翻译成目标 FPGA 芯片特有的硬件构件（查找表 LUT、触发器等）。
*   **IMPLEMENTATION（实现/布局布线）：**
    *   *Run Implementation:* 物理筑路工。决定将综合出来的查找表放在芯片的哪个具体坐标上，并完成它们之间长达数毫米的物理铜线布线。
*   **PROGRAM AND DEBUG（程序与调试）：**
    *   *Generate Bitstream:* 将布好线的版图转换成用于烧录的二进制配置文件（`.bit` 文件）。
    *   *Open Hardware Manager:* **烧录大厅。** 连接并控制物理开发板，把刚才生成的 `.bit` 比特流写进芯片 [2]。

---

