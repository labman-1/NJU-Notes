---
状态：已定稿（归档类：蒸馏 + 检索报告，无复述要求）
---

# 自制力方法论（CTDP/RSIP）全网类似内容检索 + momentum 项目分析

> 检索日期：2026-09-16。检索方式：webReader / WebFetch 直接抓取 + 英文搜索引擎。
> 上游笔记：[自制力方法论总结.md](自制力方法论总结.md)（知乎 edmond 回答的提炼）。

## 核心问题

1. 这套 CTDP/RSIP 方法论在网上其他地方有没有类似的方法、观点或衍生作品（动画、游戏、网页、App）？
2. GitHub 项目 KenXiao1/momentum 做了哪些工作、技术栈如何、基于什么理论？

---

## 一、结论速览

1. **momentum 是对该方法论的忠实且相当完整的软件实现**（469 星），作者 CMU 学生，技术栈 React + TypeScript + Tauri v2 + Supabase，明确声明基于知乎 edmond 的 CTDP 理论。
2. **该方法已形成一个小型开源生态**：GitHub 上至少 6 个衍生项目（momentum、ctdp-pomodoro、Hamon、QuietFlow、Kapozux/Momentum、momentum-ctdp）；知乎上有专门的评价问题（观点两极分化）和多篇第三方总结。
3. **传播范围局限于知乎 + GitHub**：B 站（搜"CTDP 自制力""链式时延协议""神圣座位"均无相关视频）、微信公众号（搜狗检索无相关文章）均未发现传播；贴吧、小红书匿名访问被反爬拦截，无法确认（详见"检索局限"）。
4. **思想内核在国际学术界和英文互联网都有成熟对应物**：双曲贴现 + 个人规则捆绑（Ainslie）、承诺装置（stickK/Beeminder）、Seinfeld 链条法与 r/theXeffect、游戏化习惯应用（Habitica/Forest）等。作者做的主要是**重新形式化 + 工程化整合**，而非发明全新原理；其中"用重整化群/多尺度稳态看生活"的视角是相对独特的跨学科隐喻。

---

## 二、momentum 项目分析（KenXiao1/momentum）

### 基本情况（GitHub API，2026-09-16 抓取）

| 项目 | 值 |
|---|---|
| 定位 | "A self-control web app based on CTDP theory" |
| 星标 / fork | 469 ★ / 56 fork |
| 创建 / 最近推送 | 2025-07-26 / 2026-09-12（活跃开发一年多） |
| 许可证 | GPL-3.0-only |
| 默认分支 | new-feature-branch |
| 在线地址 | https://momentumctdp.netlify.app/ （已验证可访问，标题"Momentum - 心理学驱动的专注力应用"） |
| 联系方式 | kenxiao@andrew.cmu.edu（CMU） / xiaofucheng1@gmail.com，附知乎账号链接 |

### 做了哪些工作（按 README，new-feature-branch 分支）

- **链式任务管理**：CTDP 主链的数字化——创建链（名称、神圣座位触发动作、任务时长），全屏专注模式，中断时描述具体行为后按"下必为例"判定（判失败清零 / 判允许并记为例外）。
- **任务组/嵌套链**：三三制的实现——多任务组合顺序循环执行，整组时间限制、子任务独立重复次数、实时进度追踪。
- **RSIP 国策系统**：第二代协议的完整实现——规则节点层级嵌套成规则树；**默认每天只能添加一条新规则**（对应"每天最多添加一个国策"）；**违规时该节点连同所有子节点回滚删除**（对应堆栈式熄灭）。
- **虚拟宠物系统**：6 成长阶段共 100 级（蛋→幼崽→幼年→少年→成年→长者），饥饿度/快乐度/健康度/经验值；宠物数据仅存本机不参与同步。
- **押注模式**：任务前押积分、每日押注上限，仅云同步模式可用——"近端加负值"的软件化。
- **其他**：正向计时器（无时长限制任务）、回收站（软删除）、全量导入导出（增量合并、ID 冲突处理）、Supabase 多设备云同步、玻璃拟态 UI。
- **平台**：Web（PWA）+ Tauri v2 桌面（Win/macOS/Linux 已完成，iOS/Android 进行中）。

### 技术栈（来源：GitHub languages API + package.json + README）

- **主体**：TypeScript（约 4.0 MB，绝对主力）。
- **前端**：React 18 + Vite 5 + Tailwind CSS + lucide-react 图标；玻璃拟态 UI。
- **后端/数据**：Supabase（`@supabase/supabase-js`）；PLpgSQL 约 232 KB——数据库端有大量存储过程/行级安全逻辑（环境变量 `VITE_SUPABASE_URL`、`VITE_SUPABASE_ANON_KEY`）。
- **测试**：Vitest 四套配置（单元 / 集成 / DB / 性能）+ Testing Library + msw 模拟网络层——工程规范程度在个人项目里少见。
- **跨平台**：Tauri v2 壳（Rust 代码仅约 8 KB，纯壳层），桌面构建需 Rust 工具链；要求 Node.js 20.19+/22.12+，npm/yarn。
- **部署**：Netlify（Web），GitHub Actions。

### 基于什么理论

README 开篇即声明基于知乎用户 **edmond** 的 CTDP 理论，并直接引用积分模型 `I = ∫ V(τ)·W(τ) dτ` 和三大原理（神圣座位 / 下必为例 / 线性时延）。早期 README 的 TODO 里写着"实现防止日常摆烂的 RSIP"，当前版本已实现——即该项目的路线图就是照着那篇回答的两代协议逐步落地的。**它不基于任何已发表的心理学文献，是一个"民间方法论 → 开源软件"的直接转化案例。**

---

## 三、检索结果：全网类似的方法与观点

### 3.1 直接同源衍生（同一篇回答的生态）

**GitHub（检索方式：GitHub Search API，关键词 CTDP）**

| 项目 | 星 | 形态 | 要点 |
|---|---|---|---|
| KenXiao1/momentum | 469 | Web + Tauri 桌面/移动 | 见上文 |
| Ygria/ctdp-pomodoro | 16 | Obsidian 插件 + Web PWA + Android（Capacitor） | 面向 ADHD；四原则：延迟启动、神圣座位、链条激励（连续打卡+断卡清零）、小步迭代（文明式科技树成就解锁）；pomodoro.ygria.site；MIT |
| Chemit797/Hamon | 6 | 单文件 HTML + localStorage + PWA | 名字取自 JoJo 波纹；精锐链/普通链双链、按住 5 秒的"波纹预约"（15 分钟倒计时）、判例系统、国策树（崩塌递归、水密隔舱、熄灭重启）；README 注明"原作者以 MIT License 授权改编" |
| NajdorfWinawer/QuietFlow | 2 | 单文件 HTML | "CTDP 自控稳定模型"的极简专注工具 |
| Kapozux/Momentum | 1 | 独立复刻（非 fork，MIT） | 2025-08-08 创建，README 同样声明基于 edmond 方法论 |
| all-about-momentum/momentum-ctdp | 1 | — | 组织账号下的复刻 |

**知乎**

- 原回答：https://www.zhihu.com/question/19888447/answer/1930799480401293785 （作者 cccsx，README 中称 edmond，应同一人先后改名；已抓全文，与笔记一致，另含第 23–24 节实战攻略、十步推理链）。⚠️ 页面元数据显示该回答赞同约 5.2 千（5234），与笔记中"约 5.2 万赞同"有出入，建议打开原帖核实。
- 专栏版：https://zhuanlan.zhihu.com/p/1930893902623245386
- **专门评价问题**：https://www.zhihu.com/question/1933240783298855012 《如何评价 edmond 提出的基于数学和物理模型的自控方法？》，观点两极：
  - 批评（择恩等）：缺乏心理学/神经科学依据的"民科"，有隐患；
  - 质疑（L-M-sherlock 的博客存档）：方法有效性的来源可能是"符号体系的象征合法性"（即说服力/仪式感）而非模型本身，"当原理的象征合法性削弱时，系统唯一剩下的动力"存疑；
  - 支持（Lily 等）：认知重构、可操作，对 ADHD 有实际帮助（戈多替身等实践反馈）。
- 第三方总结：《Edmond 自制力方法极简总结》 https://zhuanlan.zhihu.com/p/1931859197663908957 （已抓全文）；《对 CTDP 和 RSIP 两个自控力的方法解析》 https://zhuanlan.zhihu.com/p/1935857518497736169

### 3.2 其他中文平台

| 平台 | 检索方式与结果 |
|---|---|
| B 站 | 站内搜索"CTDP 自制力""链式时延协议""神圣座位"：**无任何相关视频**（结果全是泛自制力内容、统计学"链式中介"等无关匹配）。B 站主流自制力内容是《自控力》（麦格尼格尔）书籍解读、心理学技巧类视频 |
| 微信公众号 | 搜狗微信搜索"链式时延协议"：无相关文章（命中的全是网络协议/区块链语境） |
| 贴吧 | tieba.baidu.com 搜索返回 403，匿名无法检索 |
| 小红书 | 搜索页强制登录跳转，匿名无法检索；外部搜索引擎亦未发现相关内容 |

### 3.3 思想同源：国际学术界与英文互联网的既有对应物

以下均为检索验证过的内容（链接见文末汇总）。

**① 双曲贴现 + 个人规则捆绑 —— CTDP 理论地基的学术原型**
行为经济学家/精神病学家 George Ainslie 的 picoeconomics（《Breakdown of Will》，2001）：双曲贴现造成"临时偏好"（小即时报酬在临近时反超大延迟报酬）；自控的解法是 **reward bundling + personal rules**——把单次选择捆绑成系列，使"背叛规则"的成本放大到当下每一次选择。这与 CTDP"整条链的沉没成本与预期压缩到 τ=0 的负向尖峰"是同一思想的不同形式化。相关还有 Schelling《Egonomics, or the Art of Self-Management》(1978) 的自我谈判、Thaler & Shefrin 的 planner-doer 双自我模型（1981）。**作者的贡献是用积分式 + 策略增益 G 给这套思想做了一个工程师可读的形式化。**

**② 承诺装置（commitment devices）—— "近端加负值"的商业化实现**
stickK（耶鲁经济学家创立，违约金捐给"反慈善"组织）、Beeminder（量化目标 + "黄砖路"曲线，偏离即罚钱）。学术源头之一：Ariely & Wertenbroch (2002) 的自设截止日期实验。momentum 的"押注模式"、原方法的"锁手机找人监督"同属此类，差别是 momentum 用虚拟积分而非真钱。

**③ Seinfeld 链条法 / don't break the chain —— "神圣座位 + 清零"的大众版**
挂历画 X、不断链，归功于 Jerry Seinfeld（Brad Isaac 的 Lifehacker 专访传播）。英文社区 r/theXeffect：7×7 网格 50 天 X 挑战。Todoist 有官方指南，Chains.cc 等专门 App，GitHub 贡献图 / LeetCode / Duolingo 的 streak（连击）机制是同一设计的产品化——Duolingo 的 streak freeze（冻结券）恰好对应原文的"作息储备国策"（给基础节点留冗余）。**注意**：英文社区对链条法的主要批评——"它依赖你本来就有铁一般的意志"（r/gamedev 高赞评论）——正是原方法用"辅助链 + 侦查任务 + 判例法"试图补的缺口。

**④ 环境设计 / 摩擦力调整 —— "相关策略 / 回溯"的既有表述**
James Clear《Atomic Habits》的环境设计与两分钟规则、BJ Fogg《Tiny Habits》的锚点配方（"after I ___, I will ___"——即原文"半被动型国策：锚定必然发生的触发器"）、Stephen Guise《微习惯》、Wendy Wood 的习惯科学（给坏习惯加摩擦、给好习惯减摩擦——即"不带手机上沙发"）。

**⑤ 系统动力学视角 —— "尺度 / 稳态"的近亲**
Donella Meadows 的系统杠杆点层级（参数 < 反馈 < 信息流 < 规则 < 心智模式）：小尺度干预改变不了宏观结构，与"微观意志无法撼动宏观稳态、只有相关策略能经粗粒化上传"同构。用重整化群语言讲这件事是作者的独有包装，英文世界没找到直接对应。

**⑥ 游戏化作品 —— "运用该思想制作的网页/游戏"的英文对应**
Habitica（把任务做成 RPG：经验、装备、队伍，ADHD 社群常用）、Forest（专注种树，中途退出树枯死——单行为游戏化的标杆）、Finch（自护宠物养成，与 momentum 虚拟宠物同型）。原文直接借用的游戏机制也有出处：《钢铁雄心 4》国策树（RSIP 树状结构的原型）、《文明》科技树（ctdp-pomodoro 的成就系统）、Roguelike 元进度保留（"失败-强化-再挑战"，Dead Cells 式的永久解锁 = "内化进度不随重置丢失"）。

---

## 四、机制级对照表（CTDP/RSIP ↔ 已有方法）

| 原文机制 | 最接近的既有对应 | 差异 |
|---|---|---|
| 双曲贴现积分模型、策略增益 G | Ainslie 双曲贴现 + 个人规则 | 作者给了工程师向的形式化与筛选框架 |
| 神圣座位 + 全链清零 | Seinfeld 链条法、r/theXeffect、Duolingo streak | 原文加了"没把握不许触发"的门槛与判例法 |
| 下必为例（判例法二选一） | bright-line rules（明晰红线式承诺） | 判例法式的"永久放行"裁决是独特设计 |
| 线性时延（15 分钟预约） | 两分钟规则、执行意图（if-then）的时间锚定 | "预约链"给延迟本身也上了链条 |
| 押注/惩罚 | stickK、Beeminder、Forest 枯树 | 原文弱化金钱、强调积分/沉没成本 |
| 相关策略/回溯 | 环境设计、摩擦力调整（Wood/Clear/Fogg） | "能否经粗粒化上传到宏观尺度"是新的筛选标准 |
| 国策树/递归回溯 | 钢铁雄心国策树、文明科技树（游戏机制移植） | "每天最多加一 + 崩则连坐熄灭"的组织法是独创组合 |
| 内化进度不丢失 | Roguelike 元进度（Dead Cells） | 明确的游戏设计模式移植 |
| 尺度/稳态/不可逃逸区 | Meadows 系统杠杆点 | 重整化群表述为作者独有（未见先例） |

---

## 五、检索局限与未验证项

- 贴吧、小红书站内检索被反爬拦截（403 / 强制登录），只能通过外部搜索引擎间接判断，**不能完全排除**这两个平台存在相关内容。注意：原文自述其诞生契机恰在小红书（@Allvinn 的 ADHD 笔记评论区，作者在那里的讨论催生了这篇长文），小红书上很可能仍有相关讨论，但匿名无法核查。
- 知乎回答/专栏评论区（原回答 344 条、专栏 116 条、评价问题下回答）的 API 匿名返回 403，**这是个人实践反馈最密集的地方，未能逐条核查**；评价问题（37 个回答）SSR 只能拿到排序第一的回答全文。
- B 站/公众号的结论基于关键词"CTDP""链式时延协议""神圣座位""momentum 专注"的检索；若作者用了其他昵称传播，可能漏检。
- 英文侧未做学术数据库检索（Google Scholar 未查），Ainslie/stickK 等结论基于官方站点、picoeconomics.org、Reddit/Todoist 等公开页面。

## 六、主要来源链接汇总

- momentum 仓库：<https://github.com/KenXiao1/momentum>（README、languages、package.json 均为 2026-09-16 抓取）
- 在线版：<https://momentumctdp.netlify.app/>
- ctdp-pomodoro：<https://github.com/Ygria/ctdp-pomodoro>；Hamon：<https://github.com/Chemit797/Hamon>；QuietFlow：<https://github.com/NajdorfWinawer/QuietFlow>；Kapozux/Momentum：<https://github.com/Kapozux/Momentum>
- 知乎原回答：<https://www.zhihu.com/question/19888447/answer/1930799480401293785>；专栏版：<https://zhuanlan.zhihu.com/p/1930893902623245386>；评价问题：<https://www.zhihu.com/question/1933240783298855012>；极简总结：<https://zhuanlan.zhihu.com/p/1931859197663908957>；方法解析：<https://zhuanlan.zhihu.com/p/1935857518497736169>
- Ainslie：<https://www.picoeconomics.org/>（Breakdown of Will précis: <https://picoeconomics.org/PDFarticles/Breakdown_Will.pdf>）
- stickK：<https://www.stickk.com/>；Beeminder：<https://www.beeminder.com/>
- 链条法：Todoist 指南 <https://www.todoist.com/inspiration/dont-break-the-chain>；r/theXeffect <https://www.reddit.com/r/theXeffect/>
- 游戏化：Habitica <https://habitica.com/>；Forest（各应用商店）

---

# 第二轮检索：个人实践这套方法的经验与案例（2026-09-16）

> 检索路径：momentum GitHub issues（真实用户反馈）、知乎专栏版原文（作者的实践记录与读者反馈汇总）、知乎评价问题与原问题下的衍生回答、衍生项目 issue 区。本节【转述】指页面原文，【推断】为我的分析。

## 一、作者本人的实践（唯一完整的一手案例）

- 【转述】十几年的 ADHD + 自控问题；CTDP 实践数年，从"一节课都听不进去"到备考期连续两个月每天高效动员 8–10 小时；后发现两极分化（有 DDL 如臂使指、闲散无目标时失灵），确认单行为尺度已到极限，转而发展 RSIP。
- 【转述】当前在役约 30 个国策，是"崩塌了四五轮、上百天"迭代出来的；现役根国策之一是"在家吃完饭后必须尽快洗碗"。
- 【转述】专栏版（zhuanlan.zhihu.com/p/1930893902623245386）持续更新到 2026-05，第 23 节开头明确写道：**"文章发布三个月来，我收到了海量的反馈"**，并总结读者的两大实践问题——对 RSIP 理解有误区、"国策设计"贫瘠（只会提"早睡早起""坚持运动"这类空泛、高阻力、低效的目标）。为此他补写了实战攻略（第 23–24 节）和十步推理链。这是**作者视角对读者实践的汇总**，也是方法有效传播的直接证据。
- 【转述】作者还建议读者"可以把本文复制给 ChatGPT/Gemini/DeepSeek 辅助理解"。

## 二、momentum GitHub Issues 里的真实使用群体（最扎实的第三方实践痕迹）

469 星项目累计 120+ 个 issue/PR，从中可以还原出几类真实用户（均 2026-09-16 抓取）：

| 用户 | 使用时长/深度 | 实践痕迹 |
|---|---|---|
| Zhanyi-Zhu | 1 个多月（2026-03 起） | #115：从思维导图工具迁移国策树、报告国策组容错不生效；#118：详细反馈任务-国策联动 bug、建议"执行日追踪"；还建议国策升级等级（睡觉 9:00→7:00 分级强化）——是按方法论深度使用的用户 |
| hrx114514x | 2025-07 至 2026-03 跨度 8 个月 | 提了 15+ 个 issue：押注 30 亿积分失败清零（#114）、宠物状态同步、国策树渲染——积分滚到 30 亿说明日常重度使用 |
| zhaoyust-pixel | 2026-03 | #116 请求"可升级国策"功能（强化 +1/+2 作失败缓冲）——深度理解方法论后提出的游戏化设计 |
| KlaesAles / socialismbuilder / DengNaichen 等 | 2025-08 前后 | 数据丢失、例外规则、RSIP 与链条解耦等使用反馈 |
| 作者本人 | — | #94（2025-12）：Supabase 免费额度爆掉、数据库只读——侧面说明真实使用量不小 |

总体印象：真实用户数不算大但黏性高；反馈集中在"数据丢失打击实践积极性"（早期最致命）、"国策树/RSIP 状态 bug 破坏判例法信任"（#113：切换本地/云端丢例外规则，直接破坏"下必为例"的严肃性）。

## 三、知乎上的第三方实践/评价（两极分化）

- 评价问题（37 个回答）内【转述自搜索摘要】：戈多替身（ADHD 患者实践反馈）；有答主结合自身实践认为"CTDP 和 RSIP 作用有限，实践中感觉关键因素被忽略"；择恩批评"民科"但 edmond 本人在评论区回复；祁珞菌（HCI 硕士）做了理论对照的正面分析；L.M.Sherlock（Thoughts Memo，14.5 万粉）从心理学文献角度支持。
- 原问题下 hhhiii 的回答【转述自搜索摘要，全文抓取失败】：指出失效场景——大环境不利（长期疲惫、无明确目标）时 CTDP 会失效；RSIP 虽允许局部崩溃，但定式树维护仍依赖"约束力"。与作者自述的"两极分化"观察一致。
- 原问题下 Blues 的回答（2025-07-26，24 赞）：**即 momentum 作者本人的 App 发布帖**，含完整功能介绍与使用指南截图（由此确认 momentum 作者 = 知乎用户 Blues = Ken Xiao，CMU 在读）。

## 四、其他实践痕迹

- Ygria/ctdp-pomodoro 仅 1 个 issue（2025-09，请求白噪音功能）——有小规模真实用户，反馈极少。
- 【推断】方法的原始受众恰恰聚集在小红书 ADHD 社群（作者在 @Allvinn 笔记评论区的讨论催生了长文），但小红书站内无法匿名核查，这块实践生态的具体规模未知。

## 五、本轮结论

1. **存在真实但规模有限的实践人群**：最密集的实践痕迹在 momentum 的 issue 区和知乎评论区（后者无法核查），代表性用户有跨 8 个月的重度使用者和按方法论深度参与功能设计的用户。
2. **没有找到独立发布的完整实践长文**（"我用 CTDP/RSIP 三个月"式的复盘），公开可见的多为评价、分析和碎片反馈；最系统的实践记录仍是作者本人的自述与他对读者误区的汇总。
3. **实践中暴露的典型问题**（合并作者观察与 issue 区）：国策设计贫瘠、在"一刀切作息"上反复崩溃、工具的数据丢失/同步 bug 会直接摧毁链条约束力、大环境不利（疲惫/无目标）时方法整体失灵。
