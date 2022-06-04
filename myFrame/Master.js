// 목록별 게시글 개수
const C_cnt = 1;
const Py_cnt = 0;
const Bat_cnt = 0;
const Sh_cnt = 0;
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
var C_text = document.querySelectorAll(".C_cnt");
for (var i = C_text.length; i--;) {
    C_text[i].innerHTML = "("+C_cnt+")";
}
var Py_text = document.querySelectorAll(".Py_cnt");
for (var i = Py_text.length; i--;) {
    Py_text[i].innerHTML = "("+Py_cnt+")";
}
var Bat_text = document.querySelectorAll(".Bat_cnt");
for (var i = Bat_text.length; i--;) {
    Bat_text[i].innerHTML = "("+Bat_cnt+")";
}
var Sh_text = document.querySelectorAll(".Sh_cnt");
for (var i = Sh_text.length; i--;) {
    Sh_text[i].innerHTML = "("+Sh_cnt+")";
}