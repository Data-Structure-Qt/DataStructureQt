// script.js

// 创建一个包含20个元素并初始化为null的数组，模拟两个栈
let stack = new Array(20).fill(null);
let top1 = -1; // 栈1的顶部指针
let top2 = stack.length; // 栈2的顶部指针

// 更新栈的显示
function updateStackDisplay() {
  const container = document.getElementById('stackContainer');
  container.innerHTML = '';
  for (let i = 0; i < stack.length; i++) {
    const element = document.createElement('div');
    element.classList.add('stackElement');
    element.textContent = stack[i] !== null ? stack[i] : '';
    if (i === top1) {
      element.classList.add('stackPointer1');
    }
    if (i === top2) {
      element.classList.add('stackPointer2');
    }
    container.appendChild(element);
  }
  document.getElementById('stackStatus').textContent =
    `栈1顶: ${top1}, 栈2顶: ${top2}`;
}

// 出栈操作，栈1
function popStack1() {
  if (top1 >= 0) {
    stack[top1--] = null;
    updateStackDisplay();
  } else {
    alert('栈1为空！');
  }
}

// 入栈操作，栈1
function pushStack1() {
  const value = document.getElementById('inputStack1').value;
  if (value === '') {
    alert('请输入栈1的值！');
    return;
  }
  if (top1 < top2 - 1) {
    stack[++top1] = value;
    updateStackDisplay();
  } else {
    alert('栈已满！');
  }
}

// 入栈操作，栈2
function pushStack2() {
  const value = document.getElementById('inputStack2').value;
  if (value === '') {
    alert('请输入栈2的值！');
    return;
  }
  if (top2 - 1 > top1) {
    stack[--top2] = value;
    updateStackDisplay();
  } else {
    alert('栈已满！');
  }
}

// 出栈操作，栈2
function popStack2() {
  if (top2 < stack.length) {
    stack[top2++] = null;
    updateStackDisplay();
  } else {
    alert('栈2为空！');
  }
}

// 为按钮添加事件监听器
document.getElementById('pushStack1').addEventListener('click', pushStack1);
document.getElementById('popStack1').addEventListener('click', popStack1);
document.getElementById('pushStack2').addEventListener('click', pushStack2);
document.getElementById('popStack2').addEventListener('click', popStack2);

// 初始化时更新栈的显示
updateStackDisplay();
