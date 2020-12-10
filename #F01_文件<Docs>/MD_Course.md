# Markdown syntax guide

## 標題 (Headers)

# This is a Heading h1
## This is a Heading h2
### This is a Heading h3
#### This is a Heading h4
##### This is a Heading h5
###### This is a Heading h6


## 字體 (Emphasis)

斜體
*This text will be italic*
_This will also be italic_

粗體
**This text will be bold**
__This will also be bold__

字體組合
_You **can** combine them_

## 清單 (Lists)

### Unordered

* Item 1
* Item 2
  * Item 2a
  * Item 2b

### Ordered

1. Item 1
1. Item 2
1. Item 3
   1. Item 3a
   1. Item 3b

## 圖片 (Images)

![This is a alt text.](/image/sample.png "This is a sample image.")

## 連結 (Links)

You may be using [Markdown Live Preview](https://markdownlivepreview.com/).

## 引用塊 (Blockquotes)

> Markdown is a lightweight markup language with plain-text-formatting syntax, created in 2004 by John Gruber with Aaron Swartz.
>
>> Markdown is often used to format readme files, for writing messages in online discussion forums, and to create rich text using a plain text editor.

## 表格 (Tables)

| Left columns  | Right columns |
| ------------- |:-------------:|
| left foo      | right foo     |
| left bar      | right bar     |
| left baz      | right baz     |

## 區塊 (Blocks of code)

```
let message = 'Hello world';
alert(message);
```

## 內練代碼 (Inline code)

This web site is using `markedjs/marked`.

## 復選框 (CheckBox)

- [x] This is a complete item
- [ ] This is an incomplete item