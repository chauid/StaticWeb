// 목록별 게시글 개수
const C_cnt = 3;
const Py_cnt = 0;
const Bat_cnt = 2;
const Sh_cnt = 1;
const HTML_cnt = 0;
const CSS_cnt = 0;
const JS_cnt = 0;
const PHP_cnt = 0;
var Total_cnt = C_cnt + Py_cnt + Bat_cnt + Sh_cnt + HTML_cnt + CSS_cnt + JS_cnt + PHP_cnt;
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
var Total_text = document.querySelectorAll(".Total_cnt");
for (var i = Total_text.length; i--;) {
    Total_text[i].innerHTML = "("+Total_cnt+")";
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
var HTML_text = document.querySelectorAll(".HTML_cnt");
for (var i = HTML_text.length; i--;) {
    HTML_text[i].innerHTML = "("+HTML_cnt+")";
}
var CSS_text = document.querySelectorAll(".CSS_cnt");
for (var i = CSS_text.length; i--;) {
    CSS_text[i].innerHTML = "("+CSS_cnt+")";
}
var JS_text = document.querySelectorAll(".JS_cnt");
for (var i = JS_text.length; i--;) {
    JS_text[i].innerHTML = "("+JS_cnt+")";
}
var PHP_text = document.querySelectorAll(".PHP_cnt");
for (var i = PHP_text.length; i--;) {
    PHP_text[i].innerHTML = "("+PHP_cnt+")";
}
// 탭 문자 넣기
var codetab1 = document.querySelectorAll(".tab1");
for (var i = codetab1.length; i--;) {
    codetab1[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;";
}
var codetab2 = document.querySelectorAll(".tab2");
for (var i = codetab2.length; i--;) {
    codetab2[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
}
var codetab3 = document.querySelectorAll(".tab3");
for (var i = codetab3.length; i--;) {
    codetab3[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
}
var codetab4 = document.querySelectorAll(".tab4");
for (var i = codetab4.length; i--;) {
    codetab4[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
}
var codetab5 = document.querySelectorAll(".tab5");
for (var i = codetab5.length; i--;) {
    codetab5[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
}
var codetab6 = document.querySelectorAll(".tab6");
for (var i = codetab6.length; i--;) {
    codetab6[i].innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
}