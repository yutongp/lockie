angular.module('mean.system').controller('HeaderController', ['$scope', 'Global', function ($scope, Global) {
  $scope.global = Global;

  $scope.menu = [{
    'title': 'ABOUT',
    'link': 'about'
  }, {
    'title': 'STATUS',
    'link': 'status'
  }, {
    'title': 'KICKSTARTER',
    'link': 'kickstarter'
  }, {
    'title': 'FQA',
    'link': 'fqa'
  }];

  $scope.isCollapsed = false;
  $('.collapse').collapse();

}]);
