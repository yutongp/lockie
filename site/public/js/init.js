angular.element(document).ready(function() {
    //Fixing facebook bug with redirect
    if (window.location.hashi === "#_=_") window.location.hash = "#!";

    //Then init the app
    angular.bootstrap(document, ['mean']);
});
