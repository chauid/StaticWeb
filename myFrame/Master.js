// 목록별 게시글 개수
const list1_cnt = 4;
const list2_cnt = 3;
const list3_cnt = 2;
const list4_cnt = 1;
// 사이드바 애니메이션
function buttonclick() {
    var buttonbox = document.getElementById("Menu");
    var sidemenu = document.getElementById("Nav");
    var sideinner = document.getElementById("Nav_inner");
    var header = document.getElementById("Header");
    buttonbox.classList.toggle('-active');
    sidemenu.classList.toggle('-active');
    sideinner.classList.toggle('-active');
    header.classList.toggle('-active');
}
var list1_text = document.querySelectorAll(".list1_cnt");
for (var i = list1_text.length; i--;) {
    list1_text[i].innerHTML = "("+list1_cnt+")";
}
var list2_text = document.querySelectorAll(".list2_cnt");
for (var i = list2_text.length; i--;) {
    list2_text[i].innerHTML = "("+list2_cnt+")";
}
var list3_text = document.querySelectorAll(".list3_cnt");
for (var i = list3_text.length; i--;) {
    list3_text[i].innerHTML = "("+list3_cnt+")";
}
var list4_text = document.querySelectorAll(".list4_cnt");
for (var i = list4_text.length; i--;) {
    list4_text[i].innerHTML = "("+list4_cnt+")";
}