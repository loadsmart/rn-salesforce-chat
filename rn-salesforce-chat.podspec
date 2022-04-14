require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |s|
  s.name         = package['name'].sub(/^@loadsmart\//, '')
  s.version      = package['version']
  s.summary      = package['description']
  s.license      = package['license']

  s.authors      = package['author']
  s.homepage     = package['homepage']
  s.platform     = :ios, "12.0"

  s.source       = { :git => "https://github.com/loadsmart/rn-salesforce-chat", :tag => "v#{s.version}" }
  s.source_files  = "ios/RNSalesforceChat.{h,m}"

  s.dependency 'React'
  s.dependency 'ServiceSDK/Chat', '~> 234.1.0'
end
