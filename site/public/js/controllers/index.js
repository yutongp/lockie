angular.module('mean.system').controller('IndexController', ['$scope', 'Global', function ($scope, Global) {
    $scope.global = Global;
    // Parallax
    $('.custom-bg').each(function() {
      $(this).parallel('50%', 0.3, true);
    });
}]);
