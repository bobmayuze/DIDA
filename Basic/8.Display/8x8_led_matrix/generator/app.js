var app = angular.module('plunker', []);

app.controller('MainCtrl', function($scope) {

  $scope.name = 'Generator for LED MATRIX 8x8';

  var ledButton = {
    value: '0',
    column: 0,
    row: 0
  };

  var ledMatrixColumnsCount = 8;
  var ledMatrixRowsCount = 8;

  $scope.spriteName = "Name";
  $scope.ledMatrixRows = [];
  $scope.code = "";

  $scope.init = function() {
    for (var rowIndex = 0; rowIndex < ledMatrixRowsCount; rowIndex++) {
      var ledMatrixRow = [];
      for (var columnIndex = 0; columnIndex < ledMatrixColumnsCount; columnIndex++) {
        var lb = angular.copy(ledButton);
        lb.column = columnIndex;
        lb.row = rowIndex;
        ledMatrixRow.push(lb);
      }
      $scope.ledMatrixRows.push(ledMatrixRow);
    }
    generateCode();
  };

  $scope.$watch('spriteName', function(newValue, oldValue) {
    if (newValue != oldValue) {
      generateCode();
    }
  }, true);

  $scope.setVal = function(btn) {
    if (btn.value == '0') {
      btn.value = '1';
    } else {
      btn.value = '0';
    }
    generateCode();
  };

  $scope.clear = function() {
    angular.forEach($scope.ledMatrixRows, function(val, key) {
      angular.forEach(val, function(col, key) {
        col.value = '0';
      });
    });
    generateCode();
  };

  var generateCode = function() {
    $scope.code = "byte sprite" + $scope.spriteName + "[] = {";

    angular.forEach($scope.ledMatrixRows, function(val, key) {
      var codePart = "B";
      angular.forEach(val, function(col, key) {

        codePart += col.value;
      });
      $scope.code += codePart;
      if(key!=(ledMatrixColumnsCount-1)){
        $scope.code += ",";
      }
    });

    $scope.code += "};";
  };

});