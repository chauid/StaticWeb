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