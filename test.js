import React from 'react';
import ReactDOM from 'react-dom';

class App extends React.Component {
  constructor() {
    super();
    this.state = {
      color: 'black',
      width: '1',
      height: '1',
      x: '0',
      y: '0',
      isDrawing: false,
      isErasing: false,
      isFilling: false,
      isMoving: false,
      isResizing: false,
      isSelecting: false,
      isSaving: false,
      isLoading: false,
      isClearing: false,
      isUndoing: false,
      isRedoing: false,
      isDeleting: false,
      isCopying: false,
      isPasting: false,
      isCutting: false,
      isDeselecting: false,
      isSelectingAll: false,
      isInverting: false,
      isRotating: false,
      isFlipping: false,
      isMirroring: false,
      isZooming: false,
      isCropping: false,
      isAdjusting: false,
      isFiltering: false,
      isBlurring: false,
      isSharpening: false,
      isSmoothing: false,
      isEmbossing: false,
      isEdgeDetecting: false,
      isGrayscaling: false,
      isSepiaToning: false,
      isPosterizing: false,
      isSolarizing: false,
      isThresholding: false,
      isDithering: false,
      isInvertingColors: false,
      isChangingColors: false,
      isChangingBrightness: false,
      isChangingContrast: false,
      isChangingSaturation: false,
      isChangingHue: false,
      isChangingGamma: false,
      isChangingExposure: false,
      isChangingTemperature: false,
      isChangingTint: false,
      isChangingHighlights: false,
      isChangingShadows: false,
      isChangingWhites: false,
      isChangingBlacks: false,
      isChangingClarity: false,
      isChangingVibrance: false,
      isChangingDehaze: false,
      isChangingNoise: false,
      isChangingPixelate: false,
      isChangingBlur: false,
      isChangingSharpen: false,
      isChangingEmboss: false,
      isChangingEdgeDetect: false,
      isChangingGrayscale: false,
      isChangingSepia: false,
      isChangingPosterize: false,
      isChangingSolarize: false,
      isChangingThreshold: false,
      isChangingDither: false,
      isChangingInvertColors: false,
      isChangingColorBalance: false,
      isChangingBrightnessContrast: false,
      isChangingSaturationLightness: false,
      isChangingHueSaturation: false,
      isChangingGammaExposure: false,
      isChangingTemperatureTint: false,
      isChangingHighlightsShadows: false,
      isChangingWhitesBlacks: false,
      isChangingClarityVibrance: false,
      isChangingDehazeNoise: false,
      isChangingPixelateBlur: false,
      isChangingSharpenEmboss: false,
      isChangingEdgeDetectGrayscale: false,
      isChangingSepiaPosterize: false,
      isChangingSolarizeThreshold: false,
      isChangingDitherInvertColors: false,
      isChangingColorBalanceBrightnessContrast: false,
      isChangingSaturationLightnessHueSaturation: false,
      isChangingGammaExposureTemperatureTint: false,
      isChangingHighlightsShadowsWhitesBlacks: false,
      isChangingClarityVibranceDehazeNoise: false,
      isChangingPixelateBlurSharpenEmboss: false,
      isChangingEdgeDetectGrayscaleSepiaPosterize: false,
      isChangingSolarizeThresholdDitherInvertColors: false,
      isChangingColorBalanceBrightnessContrastSaturationLightnessHueSaturation: false,
      isChangingGammaExposureTemperatureTintHighlightsShadowsWhitesBlacks: false,
      isChangingClarityVibranceDehazeNoisePixelateBlurSharpenEmboss: false,
      isChangingEdgeDetectGrayscaleSepiaPosterizeSolarizeThresholdDitherInvertColors: false,
      isChangingColorBalanceBrightnessContrastSaturationLightnessHueSaturationGammaExposureTemperatureTintHighlightsShadowsWhitesBlacks: false,
      isChangingClarityVibranceDehazeNoisePixelateBlurSharpenEmbossEdgeDetectGrayscaleSepiaPosterizeSolarizeThresholdDitherInvertColors: false,
      isChangingColorBalanceBrightnessContrastSaturationLightnessHueSaturationGammaExposureTemperatureTintHighlightsShadowsWhitesBlacksClarityVibranceDehazeNoisePixelateBlurSharpenEmbossEdgeDetectGrayscaleSepiaPosterizeSolarizeThresholdDitherInvertColors: false
    };
  }

  render() {
    return React.createElement(
      'div',
      null,
      React.createElement(
        'h1',
        null,
        'Hello World!'
      )
    );
  }
}

ReactDOM.render(React.createElement(App, null), document.getElementById('app'));